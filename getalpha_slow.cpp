#include <set>
#include <unistd.h>

void report_set(const std::set<char> & used);

static char buf[BUFSIZE];

int main() {
	std::set<char> used;
	while (true) {
		ssize_t nread = read(0, buf, BUFSIZE);
		if (nread <= 0) break;
		for (ssize_t i = 0; i < nread; ++i) {
			used.insert(buf[i]);
		}
	}
	report_set(used);
	return 0;
}
