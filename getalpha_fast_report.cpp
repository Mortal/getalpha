#include <set>

void report_set(const std::set<char> & used);

extern "C" {

void report(char * is_used) {
	std::set<char> used;
	for (unsigned char c = 0;; ++c) {
		if (is_used[c]) used.insert(c);
		if (c == (unsigned char) 255) break;
	}
	report_set(used);
}

}
