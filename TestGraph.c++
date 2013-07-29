// TestGraph
#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair
#include <string>   // string

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

// TODO make tests for Graph

// These are interface tests
typedef testing::Types</*Graph,*/ boost::adjacency_list<boost::setS, boost::vecS, boost::directedS> > graphs;

template <typename T>
class InterfaceTest : public testing::Test {
protected:
    // --- typedefs ---

    typedef T                                       graph_type;

    typedef typename graph_type::vertex_descriptor  vertex_descriptor;
    typedef typename graph_type::edge_descriptor    edge_descriptor;

    typedef typename graph_type::vertex_iterator    vertex_iterator;
    typedef typename graph_type::edge_iterator      edge_iterator;
    typedef typename graph_type::adjacency_iterator adjacency_iterator;

    typedef typename graph_type::vertices_size_type vertices_size_type;
    typedef typename graph_type::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA;
    vertex_descriptor vdB;
    vertex_descriptor vdC;
    vertex_descriptor vdD;
    vertex_descriptor vdE;
    vertex_descriptor vdF;
    vertex_descriptor vdG;
    vertex_descriptor vdH;

    edge_descriptor edAB;
    edge_descriptor edAC;
    edge_descriptor edAE;
    edge_descriptor edBD;
    edge_descriptor edBE;
    edge_descriptor edCD;
    edge_descriptor edDE;
    edge_descriptor edDF;
    edge_descriptor edFD;
    edge_descriptor edFH;
    edge_descriptor edGH;

    // --- setUp ---
    void SetUp () {
        vdA  = add_vertex(g);
        vdB  = add_vertex(g);
        vdC  = add_vertex(g);
        vdD  = add_vertex(g);
        vdE  = add_vertex(g);
        vdF  = add_vertex(g);
        vdG  = add_vertex(g);
        vdH  = add_vertex(g);
        edAB = add_edge(vdA, vdB, g).first;
        edAC = add_edge(vdA, vdC, g).first;
        edAE = add_edge(vdA, vdE, g).first;
        edBD = add_edge(vdB, vdD, g).first;
        edBE = add_edge(vdB, vdE, g).first;
        edCD = add_edge(vdC, vdD, g).first;
        edDE = add_edge(vdD, vdE, g).first;
        edDF = add_edge(vdD, vdF, g).first;
        edFD = add_edge(vdF, vdD, g).first;
        edFH = add_edge(vdF, vdH, g).first;
        edGH = add_edge(vdG, vdH, g).first;
    }
};

TYPED_TEST_CASE(InterfaceTest, graphs);

// --- add_edge ---

TYPED_TEST(InterfaceTest, AddEdgeTest1) {
	typedef typename TestFixture::edge_descriptor edge_descriptor;
	std::pair<edge_descriptor, bool> p = add_edge(this->vdA, this->vdB, this->g);
	EXPECT_EQ(this->edAB, p.first);
	EXPECT_FALSE(p.second);
}

// --- ajacent_vertices ---

TYPED_TEST(InterfaceTest, AdjacentVerticesTest1) {
	typedef typename TestFixture::adjacency_iterator adjacency_iterator;
	typedef typename TestFixture::vertex_descriptor vertex_descriptor;
	std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(this->vdA, this->g);
	adjacency_iterator b = p.first;
	adjacency_iterator e = p.second;

	EXPECT_NE(e, b);
	if (b != e) {
	    vertex_descriptor vd = *b;
	    EXPECT_EQ(this->vdB, vd);
	}
	++b;
	if (b != e) {
	    vertex_descriptor vd = *b;
	    EXPECT_EQ(this->vdC, vd);
	}
}

// --- edge ---

TYPED_TEST(InterfaceTest, EdgeTest1) {
	typedef typename TestFixture::edge_descriptor edge_descriptor;
	std::pair<edge_descriptor, bool> p = edge(this->vdA, this->vdB, this->g);
	EXPECT_EQ(this->edAB, p.first);
	EXPECT_TRUE(p.second);
}

// --- edges ---

TYPED_TEST(InterfaceTest, EdgesTest1) {
	typedef typename TestFixture::edge_descriptor edge_descriptor;
	typedef typename TestFixture::edge_iterator edge_iterator;
	std::pair<edge_iterator, edge_iterator> p = edges(this->g);
	edge_iterator                           b = p.first;
	edge_iterator                           e = p.second;
	EXPECT_NE(e, b);
	if (b != e) {
		edge_descriptor ed = *b;
		EXPECT_EQ(this->edAB, ed);
	}
	++b;
	if (b != e) {
		edge_descriptor ed = *b;
		EXPECT_EQ(this->edAC, ed);
	}
}

// --- num_edges ---

TYPED_TEST(InterfaceTest, NumEdges1) {
	typedef typename TestFixture::edges_size_type edges_size_type;
	edges_size_type es = num_edges(this->g);
	EXPECT_EQ(11, es);
}

// --- num vertices ---

TYPED_TEST(InterfaceTest, NumVertices1) {
	typedef typename TestFixture::vertices_size_type vertices_size_type;
	vertices_size_type vs = num_vertices(this->g);
	EXPECT_EQ(8, vs);
}

// --- source ---

TYPED_TEST(InterfaceTest, Source1) {
	typedef typename TestFixture::vertex_descriptor vertex_descriptor;
	vertex_descriptor vd = source(this->edAB, this->g);
	EXPECT_EQ(this->vdA, vd);
}

// --- target ---

TYPED_TEST(InterfaceTest, Target1) {
	typedef typename TestFixture::vertex_descriptor vertex_descriptor;
	vertex_descriptor vd = target(this->edAB, this->g);
	EXPECT_EQ(this->vdB, vd);
}

// --- vertex ---

TYPED_TEST(InterfaceTest, Vertex1) {
	typedef typename TestFixture::vertex_descriptor vertex_descriptor;
	vertex_descriptor vd = vertex(0, this->g);
	EXPECT_EQ(this->vdA, vd);
}

// --- vertices ---

TYPED_TEST(InterfaceTest, Vertices1) {
	typedef typename TestFixture::vertex_descriptor vertex_descriptor;
	typedef typename TestFixture::vertex_iterator vertex_iterator;
	std::pair<vertex_iterator, vertex_iterator> p = vertices(this->g);
	vertex_iterator                             b = p.first;
	vertex_iterator                             e = p.second;
	ASSERT_NE(e, b);
	if (b != e) {
		vertex_descriptor vd = *b;
		EXPECT_EQ(this->vdA, vd);
	}
	++b;
	if (b != e) {
		vertex_descriptor vd = *b;
		EXPECT_EQ(this->vdB, vd);
	}
}

// --- has_cycle ---

TYPED_TEST(InterfaceTest, HasCycle1) {
	ASSERT_TRUE(has_cycle(this->g));
}

// --- topological_sort ---

TYPED_TEST(InterfaceTest, TopologicalSort1) {
	typedef typename TestFixture::vertex_descriptor vertex_descriptor;
	std::ostringstream out;
	topological_sort(this->g, std::ostream_iterator<vertex_descriptor>(out, " "));
	ASSERT_EQ(std::string("2 0 1 "), out.str());
}

// TODO make interface tests for Graph and adjacency_list<setS, vecS, directedS>
