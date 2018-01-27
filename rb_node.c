#include <stddef.h>

#include "rb_node.h"

/* Static sentinel structure for root and leaves cuts the required storage in half. */
static const struct rb_node RB_NULL; // members statically initialized to zero, so color is RB_BLACK

