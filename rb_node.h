/**
 * @file rb_node.h
 * @author Ivo Georgiev, ivo.georgiev@ucdenver.edu
 * @date 26 Jan 2018
 * @brief Header file (API) for a red-black tree for counting words.
 */

#ifndef RB_TREE_H
#define RB_TREE_H

/**
 * @brief Colors of the RB tree nodes.
 */
enum rb_color {
  RB_BLACK,
  RB_RED
};

/**
 * @brief The RB tree structure.
 */
struct rb_node {
  struct rb_node *parent;
  struct rb_node *left;
  struct rb_node *right;
  int count;
  char *word;
  unsigned char color;
};

/**
 * @brief Search for a node in the tree.
 *
 * Search for the @p node in the RB tree @p tree. Only the
 * key member of @p node is significant. In this case, this
 * is
 * @code{.h}
 *  char *word;
 * @endcode
 *
 * @param tree The RB tree in which to search.
 * @param node A dummy node, containing the key to search for.
 * @return A pointer to the node with that key, or NULL.
 * @note This function assumes that keys are unique.
 */
struct rb_node *
rb_find(const struct rb_node *tree, const struct rb_node *node);

/**
 * @brief Performs a left rotation.
 *
 * This function is used to restore the properties of the RB
 * tree @ tree, after rb_insert or rb_delete. It pulls the
 * right child of @p node up and makes @node its left child.
 * The original right child's left child becomes the @p node's
 * right child. This function expects that the original right
 * child of @p node is <b>not</b> RB_NULL and that the root
 * of @p tree is RB_NULL. It is the inverse of the function
 * rb_right_rotate.
 *
 * @param tree RB tree on which to perform the rotation.
 * @param node The tree node on which to perform the rotation.
 * @note If the expectations of this function are violated, it silently fails.
 */
void
rb_left_rotate(struct rb_node *tree, struct rb_node *node);

/**
 * @brief Performs a right rotation.
 *
 * This function is used to restore the properties of the RB
 * tree @ tree, after rb_insert or rb_delete. It pulls the
 * left child of @p node up and makes @node its right child.
 * The original left child's right child becomes the @p node's
 * left child. This function expects that the original left
 * child of @p node is <b>not</b> RB_NULL and that the root
 * of @p tree is RB_NULL. It is the inverse of the function
 * rb_left_rotate.
 *
 * @param tree RB tree on which to perform the rotation.
 * @param node The tree node on which to perform the rotation.
 * @note If the expectations of this function are violated, it silently fails.
 */
void
rb_right_rotate(struct rb_node *tree, struct rb_node *node);

/**
 * @brief Inserts a new node into the tree.
 *
 * This function inserts a new node @p node with a key that
 * doesn't yet exist in @p tree. Duplicates are not allowed.
 * If the same key is encountered, its count is incremented.
 * If the insert is successful, the new node is colored <b>red</b>.
 *
 * @param tree RB tree in which to insert the new node.
 * @param node
 * @return A pointer to the inserted node, or NULL, if duplicate.
 */
struct rb_node *
rb_insert(struct rb_node *tree, struct rb_node *node);

/**
 * @brief Restores RB properties after an insert.
 *
 * This function restores the RB properties of the tree @p tree,
 * after the successful insertion of the new node @node. The new
 * node starts out as <b>red</b>. There are several cases of
 * potential RB property violation and those are all handled by
 * this function.
 *
 * @param tree RB tree to restore.
 * @param node Successfully inserted node.
 */
void
rb_restore_after_insert(struct rb_node *tree, struct rb_node *node);

/**
 * @brief Finds the minimum element of the tree.
 *
 * Finds the minimum element (by key) in the tree rooted
 * at @p tree. This function serves as auxiliary for
 * rb_delete.
 *
 * @param tree The tree in which to find the minimum element.
 * @return A pointer to the minimum element.
 */
struct rb_node *
rb_min(struct rb_node *tree);

/**
 * @brief Replaces one subtree as a child of its parent with another.
 *
 * This function replaces the subtree rooted at node @p old_root
 * with the subtree rooted at node @p new_root􏰁, node @p old_root’s
 * parent becomes node @p new_root􏰁’s parent, and @p old_root’s
 * parent ends up having 􏰁@p new_root as its appropriate child. This
 * function is auxiliary to rb_delete.
 *
 * @param tree RB tree in which to perform the transplant.
 * @param old_root The subtree root to be replaced.
 * @param new_root The subtree root that replaces old_root.
 * @note The caller is responsible for updating new_root's children.
 */
void
rb_transplant(struct rb_node *tree, struct rb_node *old_root, struct rb_node *new_root);

/**
 * @brief Delete a node from a tree.
 *
 * This function deletes the node @p node from the RB tree
 * @p tree, if the node's key exists in the tree.
 *
 * @param tree RB tree from which to attempt to delete.
 * @param node Node to be deleted.
 * @return A pointer to the deleted node, or NULL, if not found.
 * @note The caller is responsible for freeing the deleted node.
 */
struct rb_node *
rb_delete(struct rb_node *tree, struct rb_node *node);

/**
 * @brief Restores RB properties after a delete.
 *
 * This function restores the RB properties of the tree @p tree
 * after the deletion of node @p orphan's parent. It is run
 * conditionally.
 *
 * @param tree RB tree after a deletion of the orphan's parent.
 * @param orphan The node whose parent was deleted.
 */
void
rb_restore_after_delete(struct rb_node *tree, struct rb_node *orphan);

#endif //RB_TREE_H
