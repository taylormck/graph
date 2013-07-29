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

#define public private
#define protected private
#define class struct

#include "Graph.h"

/*
// Useful typedefs

typedef T                                       graph_type;

typedef typename graph_type::vertex_descriptor  vertex_descriptor;
typedef typename graph_type::edge_descriptor    edge_descriptor;

typedef typename graph_type::vertex_iterator    vertex_iterator;
typedef typename graph_type::edge_iterator      edge_iterator;
typedef typename graph_type::adjacency_iterator adjacency_iterator;

typedef typename graph_type::vertices_size_type vertices_size_type;
typedef typename graph_type::edges_size_type    edges_size_type;
*/

// Tests here
