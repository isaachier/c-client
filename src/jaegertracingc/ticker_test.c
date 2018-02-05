/*
 * Copyright (c) 2018 Uber Technologies, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "jaegertracingc/ticker.h"
#include "unity.h"

static void func(void* context)
{
    TEST_ASSERT_NOT_NULL(context);
    int* x = (int*) context;
    (*x)++;
}

void test_ticker()
{
    jaeger_ticker ticker;
    jaeger_ticker_init(&ticker);
    const jaeger_duration interval = {
        0, JAEGERTRACINGC_NANOSECONDS_PER_SECOND * 0.01};
    int x = 0;
    int result = jaeger_ticker_start(&ticker, &interval, &func, &x);
    TEST_ASSERT_EQUAL(0, result);
    jaeger_duration sleep_interval = interval;
    result = nanosleep(&sleep_interval, NULL);
    TEST_ASSERT_EQUAL(0, result);
    jaeger_ticker_destroy(&ticker);
    TEST_ASSERT_GREATER_THAN(0, x);
}