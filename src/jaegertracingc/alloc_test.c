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

#include <time.h>
#include "unity.h"
#include "jaegertracingc/alloc.h"

void test_alloc()
{
    void* mem = jaeger_global_alloc->malloc(jaeger_global_alloc, 2);
    mem = jaeger_global_alloc->realloc(jaeger_global_alloc, mem, 4);
    jaeger_global_alloc->free(jaeger_global_alloc, mem);
}
