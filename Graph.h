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
#include <list>    // list

// operators
using std::rel_ops::operator!=;
using std::rel_ops::operator<=;
using std::rel_ops::operator>;
using std::rel_ops::operator>=;

// -----
// Graph
// -----

class Graph {
// --- typedefs ---
public:
    typedef int vertex_descriptor;
    typedef std::pair<vertex_descriptor, vertex_descriptor> edge_descriptor;

    typedef std::size_t vertices_size_type;
    typedef std::size_t edges_size_type;

private:
    typedef std::list<vertex_descriptor>  adjacency_list;
    typedef std::vector< adjacency_list > vertex_list;
    // The first entry in each vertex's adjacency list is the identity id

public:
    // typedef vertex_list::iterator    vertex_iterator;
    typedef adjacency_list::const_iterator adjacency_iterator;

    class vertex_iterator {
    public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef Graph::vertex_descriptor        value_type;
        typedef vertex_list::difference_type    difference_type;
        typedef const value_type*               pointer;
        typedef const value_type&               reference;

    public:
        friend bool operator == (const vertex_iterator& lhs, const vertex_iterator& rhs) {
            return (lhs.myVertex == rhs.myVertex);
        }

        friend bool operator < (const vertex_iterator& lhs, const vertex_iterator& rhs) {
            return (lhs.myVertex < rhs.myVertex);
        }

        friend vertex_iterator operator + (vertex_iterator lhs, difference_type d) {
            return lhs += d;
        }

        friend vertex_iterator operator - (vertex_iterator lhs, difference_type d) {
            return lhs -= d;
        }

        friend difference_type operator - (const vertex_iterator& lhs, const vertex_iterator& rhs) {
            return lhs.myVertex - rhs.myVertex;
        }
    private:
        vertex_list::const_iterator myVertex;

    public:
        vertex_iterator() :
            myVertex(NULL)
        {}

        vertex_iterator(vertex_list::const_iterator v) :
            myVertex(v)
        {}

        reference operator * () const {
            return *(myVertex->begin());
        }

        pointer operator -> () const {
            return &**this;
        }

        vertex_iterator& operator ++ () {
            ++myVertex;
            return *this;
        }

        vertex_iterator operator ++ (int) {
            vertex_iterator x = *this;
            ++(*this);
            return x;
        }

        vertex_iterator& operator -- () {
            --myVertex;
            return *this;
        }

        vertex_iterator operator -- (int) {
            vertex_iterator x = *this;
            --(*this);
            return x;
        }

        vertex_iterator operator += (difference_type d) {
            myVertex += d;
            return *this;
        }

        vertex_iterator operator -= (difference_type d) {
            return *this += -d;
        }

        adjacency_iterator begin() {
            return myVertex->begin();
        }

        adjacency_iterator end() {
            return myVertex->end();
        }
    };

    /**
     * Iterator over pairs of vertex_descriptors
     */
    class edge_iterator {
    public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef Graph::edge_descriptor          value_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef const value_type*               pointer;
        typedef const value_type&               reference;

    private:
        vertex_iterator mySource;
        adjacency_iterator myTarget;
        mutable value_type myEdge;

        void setEdge() const {
            vertex_descriptor source = *mySource;
            vertex_descriptor target = *myTarget;
            myEdge = std::make_pair(source, target);
        }

    public:

        friend bool operator == (const edge_iterator& lhs, const edge_iterator& rhs) {
            return ((lhs.mySource == rhs.mySource) &&
                    (lhs.myTarget == rhs.myTarget));
        }

        edge_iterator() :
            mySource(),
            myTarget(NULL)
        {}

        edge_iterator(vertex_iterator v, adjacency_iterator a) :
            mySource(v),
            myTarget(a)
        {}

        reference operator * () const {
            setEdge();
            return myEdge;
        }

        pointer operator -> () const {
            return &**this;
        }

        edge_iterator& operator ++ () {
            if(myTarget == mySource.end()) {
                ++mySource;
                myTarget = mySource.begin();
            }
            ++myTarget;
            return *this;
        }

        edge_iterator operator ++ (int) {
            edge_iterator x = *this;
            ++(*this);
            return x;
        }

        edge_iterator& operator -- () {
            if(myTarget == mySource.begin()) {
                --mySource;
                myTarget = mySource.end();
            }
            --myTarget;
            return *this;
        }

        edge_iterator operator -- (int) {
            edge_iterator x = *this;
            --(*this);
            return x;
        }
    };

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
     friend vertex_descriptor add_vertex (Graph& g) {
        vertex_descriptor v = g.myVertexList.size();
        adjacency_list newVertex(1, v);
        g.myVertexList.push_back(newVertex);
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
     friend vertices_size_type num_vertices (const Graph& g) {
        return g.myVertexList.end() - g.myVertexList.begin();
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

    vertex_list myVertexList;
    edges_size_type numEdges;

    // -----
    // valid
    // -----

    /**
     * Checks the preconditions of the graph
     * Preconditions currently checked
     * <ul>
     *     <li>Every vertex has the identity element as the first element</li>
     *     <li>There are no parallel paths</li>
     *     <li>The member <code>numEdges</code> correctly represents the number of edges in the graph</li>
     * </ul>
     *
     * @return true if the preconditions are met
     *         false otherwise
     */
     bool valid () const {
        bool result = true;
        edges_size_type edgesCounter = 0;

        for (vertex_iterator i = myVertexList.begin(); i != vertex_iterator(myVertexList.end()) && result; ++i) {
            // Assert each list is at least size 1
            // Every list MUST contain it's identity as the first element
            result = result &&
                    (std::distance(i.begin(), i.end()) > 0) &&
                    (*(i.begin()) == i - myVertexList.begin());


            // Assert there are no parallel paths
            for (adjacency_iterator j = ++i.begin(); j != i.end() && result; ++j) {
                adjacency_list::difference_type count = std::count(i.begin(), i.end(), *j);
                result = result && (count < 2);
                ++edges_size_type;
            }
        }

        result = result && (edgesCounter == numEdges);
        return result;
    }

public:
    // ------------
    // constructors
    // ------------

    /**
     * Construct a new Graph
     */
     Graph () :
        numEdges(0)
    {
        // Nothing to be done but assert preconditions
        assert(valid());
    }
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
    // TODO your code
    return true;
}

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
    // TODO your code
}

#endif // Graph_h
