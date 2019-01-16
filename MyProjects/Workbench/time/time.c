#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/sysinfo.h>

int main(void) {
	int days;
	struct sysinfo sys_info;
	time_t result;
	result = time(NULL);
	time_t * p_result;
    p_result = &result;
	//printf("%s%ju secs since the Epoch\n", asctime(localtime(&result)), (uintmax_t)result);
	printf("%s%ju secs since the Epoch\n", asctime(localtime(p_result)), (uintmax_t)result);

	if(sysinfo(&sys_info) != 0)
		perror("sysinfo");

	days = sys_info.uptime / 86400;
	printf("Uptime is: %u\n", days);
return(0);
}
