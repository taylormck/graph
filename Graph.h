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
         * TODO <your documentation>
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor, vertex_descriptor, Graph&) {
            // TODO <your code>
            edge_descriptor ed;
            bool            b;
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
         * TODO <your documentation>
         */
        friend vertex_descriptor add_vertex (Graph&) {
            // TODO <your code>
            vertex_descriptor v;
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * TODO <your documentation>
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor, const Graph&) {
            // TODO <your code>
            adjacency_iterator b = adjacency_iterator();
            adjacency_iterator e = adjacency_iterator();
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * TODO <your documentation>
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor, vertex_descriptor, const Graph&) {
            // TODO <your code>
            edge_descriptor ed;
            bool            b;
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * TODO <your documentation>
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph&) {
            // TODO <your code>
            edge_iterator b;
            edge_iterator e;
            return std::make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * TODO <your documentation>
         */
        friend edges_size_type num_edges (const Graph&) {
            // TODO <your code>
            edges_size_type s;
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * TODO <your documentation>
         */
        friend vertices_size_type num_vertices (const Graph&) {
            // TODO <your code>
            vertices_size_type s;
            return s;}

        // ------
        // source
        // ------

        /**
         * TODO <your documentation>
         */
        friend vertex_descriptor source (edge_descriptor, const Graph&) {
            // TODO <your code>
            vertex_descriptor v;
            return v;}

        // ------
        // target
        // ------

        /**
         * TODO <your documentation>
         */
        friend vertex_descriptor target (edge_descriptor, const Graph&) {
            // TODO <your code>
            vertex_descriptor v;
            return v;}

        // ------
        // vertex
        // ------

        /**
         * TODO <your documentation>
         */
        friend vertex_descriptor vertex (vertices_size_type, const Graph&) {
            // TODO <your code>
            vertex_descriptor vd;
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * TODO <your documentation>
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph&) {
            // TODO <your code>
            vertex_iterator b = vertex_iterator();
            vertex_iterator e = vertex_iterator();
            return std::make_pair(b, e);}

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
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * TODO <your documentation>
         */
        Graph () {
            // TODO <your code>
            assert(valid());}

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
    *x = 2;
    ++x;
    *x = 0;
    ++x;
    *x = 1;
    }

#endif // Graph_h
