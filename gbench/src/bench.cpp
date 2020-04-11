#include "benchmark.h"
#include "setbench.h"

static void BM_StringCreation(benchmark::State& state) {
	for (auto _ : state) std::string empty_string;
}
BENCHMARK(BM_StringCreation);

static void BM_StringCopy(benchmark::State& state) {
	std::string x = "hello";
	for (auto _ : state) std::string copy(x);
}
BENCHMARK(BM_StringCopy);

int fib(int n) {
	if (n < 2) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

static void BM_FibRecursive(benchmark::State& state) {
	for (auto _ : state) benchmark::DoNotOptimize(fib(35));
}
// BENCHMARK(BM_FibRecursive)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_FibRecursive);

template <class Set>
void bm_set(benchmark::State& state) {
	std::default_random_engine engine = std::default_random_engine{0};
	auto size = 1000;
	Set set;
	set.generate(engine, size);
	for (auto _ : state) benchmark::DoNotOptimize(set.contains(engine()));
}
static void bencher(benchmark::State& state) { bm_set<std_set>(state); }

BENCHMARK(bencher)->Range(8, 8 << 10);

static void bm_memory_access(benchmark::State& state) {
	auto bytes = state.range(0) * 1024;
	std::vector<unsigned> data(bytes / sizeof(unsigned));
	std::generate(data.begin(), data.end(), std::default_random_engine{});

	for (auto _ : state)
		for (auto& i : data) benchmark::DoNotOptimize(++i);
	state.SetBytesProcessed(state.iterations() * data.size());
}
BENCHMARK(bm_memory_access)->Range(8, 8 << 10);

BENCHMARK_MAIN();
