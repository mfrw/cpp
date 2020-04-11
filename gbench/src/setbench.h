#include <random>
#include <set>

struct std_set {
	std::set<unsigned> data;
	template <class Engine>
	void generate(Engine& e, std::size_t size) {
		for (auto i = 0u; i != size; ++i) data.insert(e());
	}
	bool contains(unsigned i) const { return data.find(i) != data.end(); }
};

