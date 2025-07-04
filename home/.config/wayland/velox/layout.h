/* velox: layout.h
 *
 * Copyright (c) 2014 Michael Forney
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef VELOX_LAYOUT_H
#define VELOX_LAYOUT_H

#include <wayland-server.h>

struct screen;
struct window;
struct swc_rectangle;

enum layer {
	TILE,
	STACK,

	NUM_LAYERS
};

struct layout {
	const struct layout_impl *impl;
	struct wl_list link;
};

struct layout *tall_layout_new(void);
struct layout *grid_layout_new(void);

struct layout *stack_layout_new(void);

void layout_add_config_nodes(void);

void layout_begin(struct layout *layout, const struct swc_rectangle *area, unsigned num_windows);
void layout_arrange(struct layout *layout, struct window *window);

#endif
