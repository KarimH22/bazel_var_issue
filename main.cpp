
#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int main(void)
{
    std::string user_name("unknown");
    char* user =secure_getenv("USER");
    if (user != nullptr)
    {
        user_name = std::string(user);
    }
    std::string filename;
#ifdef USE_VAR
    filename = std::string ("/var/tmp/test_file_")+user_name;
#else
    filename = std::string ("/tmp/test_file_")+user_name;
#endif
    FILE *fd = fopen(filename.c_str(), "wb");
    if (fd == NULL) {
        printf("failed open, errno=%d\n", errno);
        return -2;
    }
    unsigned char buffer[5]={'V','o','i','l','a'};
    size_t size=ARRAY_SIZE(buffer);
    size_t res=fwrite (buffer,  size, sizeof(*buffer), fd );
    printf("write %lu--- size is %lu \n",res, size );
    if ( res != sizeof(*buffer)) {
        printf("FAILED \n");
        fclose(fd);
    }
    fclose(fd);
    return (EXIT_SUCCESS);
}