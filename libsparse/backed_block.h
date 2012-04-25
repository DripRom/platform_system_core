/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BACKED_BLOCK_H_
#define _BACKED_BLOCK_H_

struct backed_block_list;

typedef void (*data_block_callback_t)(void *priv, int64_t off, void *data,
		int len);
typedef void (*data_block_fill_callback_t)(void *priv, int64_t off,
		unsigned int fill_val, int len);
typedef void (*data_block_file_callback_t)(void *priv, int64_t off,
		const char *file, int64_t offset, int len);

void for_each_data_block(struct backed_block_list *b,
	data_block_callback_t data_func,
	data_block_file_callback_t file_func,
	data_block_fill_callback_t fill_func,
	void *priv, unsigned int);

void queue_data_block(struct backed_block_list *b,void *data, unsigned int len,
		unsigned int block);
void queue_fill_block(struct backed_block_list *b,unsigned int fill_val,
		unsigned int len, unsigned int block);
void queue_data_file(struct backed_block_list *b,const char *filename,
		int64_t offset, unsigned int len, unsigned int block);

struct backed_block_list *backed_block_list_new(void);
void backed_block_list_destroy(struct backed_block_list *b);

#endif
