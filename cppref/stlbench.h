#ifndef STLBENCH_H_SHA6PACV
#define STLBENCH_H_SHA6PACV

#include <set>
#include <unordered_set>
#include <vector>

namespace set {

struct std_set {
	std::set<unsigned> data;
	template <class Engine>
	void generate(Engine& e, std::size_t size) {
		for (auto i = 0u; i != size; ++i) data.insert(e());
	}
	bool contains(unsigned i) const { return data.find(i) != data.end(); }
};

struct std_unordered_set {
	std::unordered_set<unsigned> data;
	template <class Engine>
	void generate(Engine& e, std::size_t size) {
		for (auto i = 0u; i != size; ++i) data.insert(e());
	}
	bool contains(unsigned i) const { return data.find(i) != data.end(); }
};

struct linear_set {
	std::vector<unsigned> data;
	template <class Engine>
	void generate(Engine& e, std::size_t size) {
		data.resize(size);
		std::generate(data.begin(), data.end(), e);
	}

	bool contains(unsigned i) const {
		return std::find(data.begin(), data.end(), i) != data.end();
	}
};

struct sorted_set {
	std::vector<unsigned> data;
	template <class Engine>
	void generate(Engine& e, std::size_t size) {
		data.resize(size);
		std::generate(data.begin(), data.end(), e);
		std::sort(data.begin(), data.end());
	}
	bool contains(unsigned i) const {
		return std::binary_search(data.begin(), data.end(), i);
	}
};

}  // namespace set

#endif /* end of include guard: STLBENCH_H_SHA6PACV */
