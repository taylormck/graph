// TestGraph
#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp"  // adjacency_list
#include "boost/graph/topological_sort.hpp"// topological_sort

#include "gtest/gtest.h"

// Include Graph's required headers before the compiler defines
#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector

#define private public
#define protected public
#define class struct
#include "Graph.h"

// These are implementation dependent tests
// This class contains some typedefs to make the constructor tests more readable
class ConstructorTest : public testing::Test {
protected:
	typedef Graph graph_type;
	typedef typename graph_type::vertex_descriptor  vertex_descriptor;
	typedef typename graph_type::edge_descriptor    edge_descriptor;

	typedef typename graph_type::vertex_iterator    vertex_iterator;
	typedef typename graph_type::edge_iterator      edge_iterator;
	typedef typename graph_type::adjacency_iterator adjacency_iterator;

	typedef typename graph_type::vertices_size_type vertices_size_type;
	typedef typename graph_type::edges_size_type    edges_size_type;
};

TEST_F(ConstructorTest, EmptyTest) {
	ASSERT_TRUE(true);
}

// TODO make tests for Graph

// These are interface tests
typedef testing::Types<Graph, boost::adjacency_list<boost::setS, boost::vecS, boost::directedS> > graphs;

template <typename T>
class InterfaceTest : public testing::Test {
protected:

};

TYPED_TEST_CASE(InterfaceTest, graphs);

// TODO make interface tests for Graph and adjacency_list<setS, vecS, directedS>