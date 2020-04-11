#include "stlbench.h"

#include <random>

#include "benchmark/benchmark.h"

void bm_memory_access(benchmark::State& state) {
	auto bytes = state.range(0) * 1024;
	std::vector<unsigned> data(bytes / sizeof(unsigned));
	std::generate(data.begin(), data.end(), std::default_random_engine{});
	for (auto _ : state)
		for (auto& i : data) benchmark::DoNotOptimize(++i);
	state.SetBytesProcessed(state.iterations() * data.size());
}
BENCHMARK(bm_memory_access)->Range(8, 512);

void bm_stride(benchmark::State& state) {
	std::vector<unsigned> data(128 * 1024 * 1024);
	std::generate(data.begin(), data.end(), std::default_random_engine{});
	auto stride = state.range(0) / sizeof(unsigned);
	for (auto _ : state)
		for (auto i = 0u; i < data.size(); i += stride)
			benchmark::DoNotOptimize(++data[i]);
	state.SetBytesProcessed(state.iterations() * data.size() *
				sizeof(unsigned) / stride);
}
BENCHMARK(bm_stride)->Range(8, 512);

template <class Set>
void bm_set(benchmark::State& state) {
	std::default_random_engine engine(0);
	auto size = state.range(0) / sizeof(unsigned);
	Set set;
	set.generate(engine, size);
	for (auto _ : state) benchmark::DoNotOptimize(set.contains(engine()));
}
BENCHMARK_TEMPLATE(bm_set, set::std_set)->DenseRange(0, 512, 128);
BENCHMARK_TEMPLATE(bm_set, set::std_unordered_set)->DenseRange(0, 512, 128);
BENCHMARK_TEMPLATE(bm_set, set::linear_set)->DenseRange(0, 512, 128);
BENCHMARK_TEMPLATE(bm_set, set::sorted_set)->DenseRange(0, 512, 128);

void accumulate_fork(std::vector<unsigned>& sums,
		     const std::vector<unsigned>& data) {
	const auto per_thread = data.size() / sums.size();
	auto task = [&](std::size_t thread_index) {
		auto begin = data.begin() + thread_index * per_thread;
		auto end = data.begin() + (thread_index + 1) * per_thread;

		auto& result = sums[thread_index];
		for (auto cur = begin; cur != end; ++cur) result += *cur;
		execute_parallel(sums.size(), task);
	};
}

BENCHMARK_MAIN();
