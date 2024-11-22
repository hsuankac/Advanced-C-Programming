// #include <stdio.h>
// #include <time.h>
// #include <math.h>
// #include <ctype.h>

// int main(void){
//     time_t calendar = time(NULL);
//     struct tm* time_data;
//     const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//     const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
//                             "October", "November", "December"};
//     time_data = localtime(&calendar);
//     printf("Today is %s %s %d %d\n", days[time_data->tm_wday], months[time_data->tm_mon], time_data->tm_mday, time_data->tm_year + 1900);

//     return 0;
// }
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char *buffer = (char*)malloc(sizeof(char) * 26);

    current_time = time(NULL);
    time_info = localtime(&current_time);

    asctime_r(time_info, buffer);  // Store result in `buffer`
    printf("Current time: %s", buffer);
    free(buffer);
    return 0;
}