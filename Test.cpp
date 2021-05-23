#include "doctest.h"

#include "BinaryTree.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace ariel;
using namespace std;

TEST_CASE("int BT basic")
{
    BinaryTree<int> tree_of_ints;
    CHECK_NOTHROW(tree_of_ints.add_root(1));
    CHECK_NOTHROW(tree_of_ints.add_left(1, 9));
    CHECK_NOTHROW(tree_of_ints.add_left(9, 4));
    CHECK_NOTHROW(tree_of_ints.add_right(9, 5));
    CHECK_NOTHROW(tree_of_ints.add_right(1, 3));
    CHECK_NOTHROW(tree_of_ints.add_left(1, 2));
    CHECK_THROWS(tree_of_ints.add_right(13, 3));
    CHECK_THROWS(tree_of_ints.add_left(20, 2));
    CHECK(tree_of_ints.contains(tree_of_ints.get_root(), 5));
    CHECK_FALSE(tree_of_ints.contains(tree_of_ints.get_root(), 20));
    CHECK(tree_of_ints.get_root().data == 1);
    Node<int> temp = tree_of_ints.get_root();
    CHECK_NOTHROW(tree_of_ints.add_root(7));
    CHECK_THROWS(tree_of_ints.add_right(1, 3));
    CHECK_THROWS(tree_of_ints.add_left(1, 2));
    CHECK_FALSE(tree_of_ints.contains(tree_of_ints.get_root(), 1));
    CHECK(tree_of_ints.get_root().data == 7);
    CHECK(tree_of_ints.get_root().left == 2);
    CHECK(tree_of_ints.contains(tree_of_ints.get_root(), 5) == true);
    CHECK(tree_of_ints.contains(tree_of_ints.get_root(), 4) == true);
    CHECK_THROWS(tree_of_ints.contains(temp, 2));
}

TEST_CASE("string BT basic")
{
    BinaryTree<string> tree_of_strings;
    CHECK_NOTHROW(tree_of_strings.add_root("root"));
    CHECK_NOTHROW(tree_of_strings.add_left("root", "first"));
    CHECK_NOTHROW(tree_of_strings.add_left("first", "grand"));
    CHECK_NOTHROW(tree_of_strings.add_right("first", "hey"));
    CHECK_NOTHROW(tree_of_strings.add_right("root", "you"));
    CHECK_NOTHROW(tree_of_strings.add_left("root", "are"));
    CHECK_THROWS(tree_of_strings.add_right("bat", "you"));
    CHECK_THROWS(tree_of_strings.add_left("rat", "are"));
    CHECK(tree_of_strings.contains(tree_of_strings.get_root(), "not"));
    CHECK_FALSE(tree_of_strings.contains(tree_of_strings.get_root(), "here"));
    CHECK(tree_of_strings.get_root().data == "root");
    CHECK_NOTHROW(tree_of_strings.add_root("new"));
    CHECK_FALSE(tree_of_strings.contains(tree_of_strings.get_root(), "root"));
    CHECK_THROWS(tree_of_strings.add_right("root", "you"));
    CHECK_THROWS(tree_of_strings.add_left("root", "are"));
    CHECK(tree_of_strings.get_root().data == "new");
    CHECK(tree_of_strings.get_root().left == "are");
}

TEST_CASE("char BT basic")
{
    BinaryTree<char> tree_of_char;
    CHECK_NOTHROW(tree_of_char.add_root('r'));
    CHECK_NOTHROW(tree_of_char.add_left('r', 'f'));
    CHECK_NOTHROW(tree_of_char.add_left('f', 'g'));
    CHECK_NOTHROW(tree_of_char.add_right('f', 'h'));
    CHECK_NOTHROW(tree_of_char.add_right('r', 'y'));
    CHECK_NOTHROW(tree_of_char.add_left('r', 'a'));
    CHECK_THROWS(tree_of_char.add_right('b', 'y'));
    CHECK_THROWS(tree_of_char.add_left('$', 'a'));
    CHECK(tree_of_char.contains(tree_of_char.get_root(), '!'));
    CHECK_FALSE(tree_of_char.contains(tree_of_char.get_root(), 'h'));
    CHECK(tree_of_char.get_root().data == 'r');
    CHECK_NOTHROW(tree_of_char.add_root('n'));
    CHECK_FALSE(tree_of_char.contains(tree_of_char.get_root(), 'r'));
    CHECK_THROWS(tree_of_char.add_right('r', 'y'));
    CHECK_THROWS(tree_of_char.add_left('r', 'a'));
    CHECK(tree_of_char.get_root().data == 'n');
    CHECK(tree_of_char.get_root().left == 'a');
}

TEST_CASE("int BT")
{
    BinaryTree<int> tree_of_ints;
    CHECK_NOTHROW(tree_of_ints.add_root(1));
    CHECK_NOTHROW(tree_of_ints.add_left(1, 2));
    CHECK_NOTHROW(tree_of_ints.add_right(1, 3));
    CHECK_NOTHROW(tree_of_ints.add_left(2, 4));
    CHECK_NOTHROW(tree_of_ints.add_right(2, 5));
    CHECK_NOTHROW(tree_of_ints.add_left(3, 6));
    CHECK_NOTHROW(tree_of_ints.add_right(3, 7));
    CHECK_NOTHROW(tree_of_ints.add_left(4, 8));
    CHECK_NOTHROW(tree_of_ints.add_right(4, 9));
    CHECK_NOTHROW(tree_of_ints.add_left(5, 10));
    CHECK_NOTHROW(tree_of_ints.add_right(5, 11));
    CHECK_NOTHROW(tree_of_ints.add_left(6, 12));
    CHECK_NOTHROW(tree_of_ints.add_right(6, 13));
    CHECK_NOTHROW(tree_of_ints.add_left(7, 14));
    CHECK_NOTHROW(tree_of_ints.add_right(7, 15));

    for (int i = 1; i < 16; i++)
    {
        CHECK(tree_of_ints.contains(tree_of_ints.get_root(), i));
    }

    vector<int> tempVector = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    auto itPre = tree_of_ints.begin_preorder();
    unsigned int i = 0;
    while (itPre != tree_of_ints.end_preorder())
    {
        CHECK(itPre == tempVector[i]);
        i++;
        itPre++;
    }

    tempVector = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
    auto itIn = tree_of_ints.begin_inorder();
    i = 0;
    while (itIn != tree_of_ints.end_inorder())
    {
        CHECK(itIn == tempVector[i]);
        i++;
    }

    tempVector = {8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1};
    auto itPost = tree_of_ints.begin_postorder();
    i = 0;
    while (itPost != tree_of_ints.end_postorder())
    {
        CHECK(itPost == tempVector[i]);
        i++;
    }
}

TEST_CASE("string BT")
{
    BinaryTree<string> tree_of_string;
    CHECK_NOTHROW(tree_of_string.add_root("one"));
    CHECK_NOTHROW(tree_of_string.add_left("one", "two"));
    CHECK_NOTHROW(tree_of_string.add_right("one", "three"));
    CHECK_NOTHROW(tree_of_string.add_left("two", "four"));
    CHECK_NOTHROW(tree_of_string.add_right("two", "five"));
    CHECK_NOTHROW(tree_of_string.add_left("three", "six"));
    CHECK_NOTHROW(tree_of_string.add_right("three", "seven"));
    CHECK_NOTHROW(tree_of_string.add_left("four", "eight"));
    CHECK_NOTHROW(tree_of_string.add_right("four", "nine"));
    CHECK_NOTHROW(tree_of_string.add_left("five", "ten"));
    CHECK_NOTHROW(tree_of_string.add_right("five", "eleven"));
    CHECK_NOTHROW(tree_of_string.add_left("six", "twelve"));
    CHECK_NOTHROW(tree_of_string.add_right("six", "thirteen"));
    CHECK_NOTHROW(tree_of_string.add_left("seven", "fourteen"));
    CHECK_NOTHROW(tree_of_string.add_right("seven", "fifthteen"));

    vector<string> tempVector = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifthteen"};
    for (unsigned int i = 1; i < 16; i++)
    {
        CHECK(tree_of_string.contains(tree_of_string.get_root(), tempVector[i]));
    }

    tempVector = {"one", "two", "four", "eight", "nine", "five", "ten", "eleven", "three", "six", "twelve", "thirteen", "seven", "fourteen", "fifthteen"};
    auto itPre = tree_of_string.begin_preorder();
    unsigned int i = 0;
    while (itPre != tree_of_string.end_preorder())
    {
        CHECK(itPre == tempVector[i]);
        i++;
    }

    tempVector = {"eight", "four", "nine", "two", "ten", "five", "eleven", "one", "twelve", "six", "thirteen", "three", "fourteen", "seven", "fifthteen"};
    auto itIn = tree_of_string.begin_inorder();
    i = 0;
    while (itIn != tree_of_string.end_inorder())
    {
        CHECK(itIn == tempVector[i]);
        i++;
    }

    tempVector = {"eight", "nine", "four", "ten", "eleven", "five", "two", "twelve", "thirteen", "six", "fourteen", "fifthteen", "seven", "three", "one"};
    auto itPost = tree_of_string.begin_postorder();
    i = 0;
    while (itPost != tree_of_string.end_postorder())
    {
        CHECK(itPost == tempVector[i]);
        i++;
    }
}

TEST_CASE("char BT")
{
    BinaryTree<char> tree_of_char;
    CHECK_NOTHROW(tree_of_char.add_root('a'));
    CHECK_NOTHROW(tree_of_char.add_left('a', 'b'));
    CHECK_NOTHROW(tree_of_char.add_right('a', 'c'));
    CHECK_NOTHROW(tree_of_char.add_left('b', 'd'));
    CHECK_NOTHROW(tree_of_char.add_right('b', 'e'));
    CHECK_NOTHROW(tree_of_char.add_left('c', 'f'));
    CHECK_NOTHROW(tree_of_char.add_right('c', 'g'));
    CHECK_NOTHROW(tree_of_char.add_left('d', 'h'));
    CHECK_NOTHROW(tree_of_char.add_right('d', 'i'));
    CHECK_NOTHROW(tree_of_char.add_left('e', 'j'));
    CHECK_NOTHROW(tree_of_char.add_right('e', 'k'));
    CHECK_NOTHROW(tree_of_char.add_left('f', 'l'));
    CHECK_NOTHROW(tree_of_char.add_right('f', 'm'));
    CHECK_NOTHROW(tree_of_char.add_left('g', 'n'));
    CHECK_NOTHROW(tree_of_char.add_right('g', 'o'));

    vector<char> tempVector = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'};
    for (unsigned int i = 1; i < 16; i++)
    {
        CHECK(tree_of_char.contains(tree_of_char.get_root(), tempVector[i]));
    }

    tempVector = {'a', 'b', 'd', 'h', 'i', 'e', 'j', 'k', 'c', 'f', 'l', 'm', 'g', 'n', 'o'};
    auto itPre = tree_of_char.begin_preorder();
    unsigned int i = 0;
    while (itPre != tree_of_char.end_preorder())
    {
        CHECK(itPre == tempVector[i]);
        i++;
    }

    tempVector = {'h', 'd', 'i', 'b', 'j', 'e', 'k', 'a', 'l', 'f', 'm', 'c', 'n', 'g', 'o'};
    auto itIn = tree_of_char.begin_inorder();
    i = 0;
    while (itIn != tree_of_char.end_inorder())
    {
        CHECK(itIn == tempVector[i]);
        i++;
    }

    tempVector = {'h', 'i', 'd', 'j', 'k', 'e', 'b', 'l', 'm', 'f', 'n', 'o', 'g', 'c', 'a'};
    auto itPost = tree_of_char.begin_postorder();
    i = 0;
    while (itPost != tree_of_char.end_postorder())
    {
        CHECK(itPost == tempVector[i]);
        i++;
    }
}
