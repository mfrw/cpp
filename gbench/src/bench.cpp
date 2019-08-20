#include "benchmark.h"

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

BENCHMARK_MAIN();
