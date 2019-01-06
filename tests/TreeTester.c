//
// Created by ezgi on 29.12.2018.
//
#include </home/ezgi/CLionProjects/RAS111/include/DataStructures/Tree/Tree.h>


static char *const STR_TREE = "Tree";

void testTreeAddition()
{

}

int onVisitedTreeNode(int value, void* env){
    LinkedList* items = (LinkedList*)env;
    linkedListAdd(items, value);
    return TRUE;
}


void testTreeInorder()
{
    TreeNode* tree= treeCreateNode(23);
    treeInsert(tree, 34);
    treeInsert(tree, 17);
    LinkedList* items = linkedListNew();
    treeInorder(tree, &onVisitedTreeNode, items);

    LinkedList* expectedOrder= linkedListNew();
    linkedListAdd(expectedOrder, 17);
    linkedListAdd(expectedOrder, 23);
    linkedListAdd(expectedOrder, 34);

    for (int i =0;i < items->size;i++) {
        int value = linkedListGet(items, i);
        int expectedValue = linkedListGet(expectedOrder, i);
        assert(expectedValue==value);
    }
}

void testTreeFind()
{
    TreeNode* tree= treeCreateNode(23);
    treeInsert(tree, 34);
    treeInsert(tree, 17);
    treeInsert(tree, 19);
    treeInsert(tree, 40);
    assert(treeFind(17, tree) == 1);
    assert(treeFind(40, tree) == 1);
    assert(treeFind(14, tree) == 0);
}

void treeTestAll()
{
    log(STR_TREE, "Started testing tree");
    testTreeInorder();
    testTreeFind();
    log(STR_TREE, "Finished testing tree");
}

