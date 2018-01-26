#ifndef RB_TREE_H
#define RB_TREE_H

// TODO (1) rb struct (2) RBNULL static node (3) functions

enum rb_color {
  RB_BLACK,
  RB_RED
};

struct rb_tree {
  struct rb_tree *parent;
  struct rb_tree *left;
  struct rb_tree *right;
  int count;
  char *word;
  unsigned char color;
};

/*
rb_find
rb_left_rotate
rb_right_rotate
rb_insert
rb_restore_after_insert
rb_transplant
rb_delete
rb_restore_after_delete
*/

#endif //RB_TREE_H
