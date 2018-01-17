/*
 * ThreadPool.h
 *
 *  Created on: Jan 16, 2018
 *      Author: avihay
 */

#include "Task.h"
#include <queue>
#include <pthread.h>
#include <iostream>

using namespace std;

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

class ThreadPool {
 public:
    ThreadPool(int threadsNum);
    void addTask(Task *task);
    void terminate();
    virtual ~ThreadPool();
 private:
    queue<Task *> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;

    static void *execute(void *arg);
};

#endif /* THREADPOOL_H_ */
