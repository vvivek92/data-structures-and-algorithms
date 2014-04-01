typedef struct node {
    int i;
    struct node * next;
} node;
struct node * full_reverse_iterative(struct node *);
struct node * full_reverse_recursive(struct node *);
struct node * reverse_iterative_every_two_nodes(struct node *);
struct node * reverse_recursive_every_two_nodes(struct node *);
struct node * reverse_recursive_every_k_nodes(struct node *,int);
struct node * reverse_iterative_every_k_nodes(struct node *,int);
