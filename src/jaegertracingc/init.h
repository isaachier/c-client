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

#ifndef JAEGERTRACINGC_INIT_H
#define JAEGERTRACINGC_INIT_H

#include "jaegertracingc/common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct jaeger_allocator;
struct jaeger_logger;

/* Use this function to initialize the library before calling any functions.
 * For logger, use a custom logger, or NULL to use the built-in stdout/stderr
 * logger.
 * For alloc, use a custom allocator, or NULL to use the built-in allocator.
 */
void jaeger_init_lib(struct jaeger_logger* logger,
                     struct jaeger_allocator* alloc);

struct jaeger_allocator* jaeger_default_allocator();

struct jaeger_logger* jaeger_default_logger();

#ifdef __cplusplus
} /* extern C */
#endif /* __cplusplus */

#endif /* JAEGERTRACINGC_INIT_H */