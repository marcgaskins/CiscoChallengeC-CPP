/* 
 * File:   thread_question.c
 * Author: marcd
 *
 * Created on February 3, 2019, 9:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int g_keep_running = 1;

void *thread_func(void *arg)
{
    size_t ret = 0;
    (void)arg;
    while (g_keep_running)
    {
        ret += 1;
    }
    printf("\nOk.\n");
    return (void*)ret;
}

int main(int argc, char **argv)
{
    pthread_t thr;
    pthread_create(&thr, NULL, thread_func, NULL);
    sleep(2);
    g_keep_running = 0;
    pthread_join(thr, NULL);
    return 0;
}
