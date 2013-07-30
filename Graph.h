// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector

// -----
// Graph
// -----

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor;  // fix!
        typedef int edge_descriptor;    // fix!

        typedef int* vertex_iterator;    // fix!
        typedef int* edge_iterator;      // fix!
        typedef int* adjacency_iterator; // fix!

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * Adds edge (u,v) to the graph and returns the edge descriptor for the
         * new edge. For graphs that do not allow parallel edges, if the edge is
         * already in the graph then a duplicate will not be added and the bool
         * flag will be false. When the flag is false, the returned edge
         * descriptor points to the already existing edge.
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor, vertex_descriptor, Graph&) {
            // TODO <your code>
            edge_descriptor ed;
            bool            b;
            return std::make_pair(ed, b);
        }

        // ----------
        // add_vertex
        // ----------

        /**
         * Adds a vertex to the graph and returns the vertex descriptor for the
         * new vertex.
         */
        friend vertex_descriptor add_vertex (Graph&) {
            // TODO <your code>
            vertex_descriptor v;
            return v;
        }

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * Returns an iterator-range providing access to the vertices adjacent
         * to vertex u in graph g. For example, if u -> v is an edge in the
         * graph, then v will be in this iterator-range.
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor, const Graph&) {
            // TODO <your code>
            adjacency_iterator b = adjacency_iterator();
            adjacency_iterator e = adjacency_iterator();
            return std::make_pair(b, e);
        }

        // ----
        // edge
        // ----

        /**
         * If an edge from vertex u to vertex v exists, return a pair containing
         * one such edge and true. If there are no edges between u and v, return
         * a pair with an arbitrary edge descriptor and false.
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor, vertex_descriptor, const Graph&) {
            // TODO <your code>
            edge_descriptor ed;
            bool            b;
            return std::make_pair(ed, b);
        }

        // -----
        // edges
        // -----

        /**
         * Returns an iterator-range providing access to the edge set of graph
         * g.
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph&) {
            // TODO <your code>
            edge_iterator b;
            edge_iterator e;
            return std::make_pair(b, e);
        }

        // ---------
        // num_edges
        // ---------

        /**
         * Returns the number of edges in the graph g.
         */
        friend edges_size_type num_edges (const Graph&) {
            // TODO <your code>
            edges_size_type s;
            return s;
        }

        // ------------
        // num_vertices
        // ------------

        /**
         * Returns the number of vertices in the graph g.
         */
        friend vertices_size_type num_vertices (const Graph&) {
            // TODO <your code>
            vertices_size_type s;
            return s;
        }

        // ------
        // source
        // ------

        /**
         * Returns the source vertex of edge e.
         */
        friend vertex_descriptor source (edge_descriptor, const Graph&) {
            // TODO <your code>
            vertex_descriptor v;
            return v;
        }

        // ------
        // target
        // ------

        /**
         * Returns the target vertex of edge e.
         */
        friend vertex_descriptor target (edge_descriptor, const Graph&) {
            // TODO <your code>
            vertex_descriptor v;
            return v;
        }

        // ------
        // vertex
        // ------

        /**
         * Returns the nth vertex in the graph's vertex list.
         */
        friend vertex_descriptor vertex (vertices_size_type n, const Graph&) {
            // TODO <your code>
            vertex_descriptor vd;
            return vd;
        }

        // --------
        // vertices
        // --------

        /**
         * Returns an iterator-range providing access to the vertex set of
         * graph g.
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph&) {
            // TODO <your code>
            vertex_iterator b = vertex_iterator();
            vertex_iterator e = vertex_iterator();
            return std::make_pair(b, e);
        }

    private:
        // ----
        // data
        // ----

        std::vector< std::vector<vertex_descriptor> > g; // something like this

        // -----
        // valid
        // -----

        /**
         * TODO <your documentation>
         */
        bool valid () const {
            // TODO <your code>
            return true;
        }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Construct a new Graph
         */
        Graph () {
            // TODO <your code>
            assert(valid());
        }

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
};

// ---------
// has_cycle
// ---------

/**
 * depth-first traversal
 * three colors
 * TODO <your documentation>
 */
template <typename G>
bool has_cycle (const G& g) {
    return true;}

// ----------------
// topological_sort
// ----------------

/**
 * depth-first traversal
 * two colors
 * TODO <your documentation>
 * @throws Boost's not_a_dag exception if has_cycle()
 */
template <typename G, typename OI>
void topological_sort (const G& g, OI x) {
    if (has_cycle(g))
        throw boost::not_a_dag();
    *x = 2;
    ++x;
    *x = 0;
    ++x;
    *x = 1;
    }

#endif // Graph_h
