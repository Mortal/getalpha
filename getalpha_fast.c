#include <unistd.h>

static unsigned char buf[BUFSIZE];

void report(char * is_used);

int main() {
	char is_used[256];
	for (size_t i = 0; i < 256; ++i) is_used[i] = 0;
	while (1) {
		ssize_t nread = read(0, buf, BUFSIZE);
		if (nread <= 0) break;
		for (ssize_t i = 0; i < nread; ++i) {
			is_used[buf[i]] = 1;
		}
	}
	report(is_used);
	return 0;
}
