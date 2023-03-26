#include <stdio.h>
#include <stdlib.h>
#include "./src/tree.hpp"
#include "./src/diff.hpp"
#include "./src/lexer.hpp"

int main() {

    char* str = (char*)calloc( MAX_SIZE, sizeof(char) ); 
    fgets( str, MAX_SIZE, stdin );
    printf( "%s\n", str);
    node_t node = {};
    tree_ctor( &node );
    int err = get_tree( str, &node );
    
    if ( err ) {

        free( str );
        tree_dtor( &node, node.node );    
        return 0;

    }

    printf("\n");
    node_t* res = Diff( &node );
    const_erase( res );
    tree_latex( res, &node );
    tree_dtor( res, res->node );
    tree_dtor( &node, node.node);
    free(res);
    free(str);
    return 0;

}