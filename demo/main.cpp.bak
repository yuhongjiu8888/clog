extern "C"
{
#include "log.h"
}

int main()
{
    FILE *fp = fopen("log.txt", "aw+");

    log_add_fp(fp, LOG_DEBUG);

    log_debug("test");
    log_info("test1");
    log_warn("test");
    log_error("....");

    LOG_DEBUG("11111111111111111");
    LOG_DEBUG("22222222222222222");
    LOG_ERROR("3333333333333 %d", 123);
    fclose(fp);
    return 0;
}