extern "C"
{
#include "log.h"
}

int main()
{
    // FILE *fp = fopen("log.txt", "aw+");

    // log_add_fp(fp, LOG_DEBUG);

    log_debug("test");
    log_info("test1");
    log_warn("test");
    log_error("....");

    LOG_DEBUG("11111111111111111");
    LOG_DEBUG("22222222222222222");
    LOG_ERROR("3333333333333 %d", 123);

    for (int i = 0; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            LOG_INFO("i :%d", i);
        }
        else if (i % 5 == 0)
        {
            LOG_TRACE("i :%d", i);
        }
        else
        {
            LOG_ERROR("i: %d", i);
        }
    }

    // fclose(fp);
    return 0;
}