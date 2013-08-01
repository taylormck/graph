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
#include <set>     // set
#include <queue>   // priority_queue
#include <map>     // map

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
    typedef std::set< edge_descriptor >  edge_list;

public:
    typedef adjacency_list::const_iterator adjacency_iterator;
    typedef edge_list::const_iterator      edge_iterator;

    class vertex_iterator {
    private:
        typedef vertex_list::iterator       vertex_list_iterator;
        typedef vertex_list::const_iterator const_vertex_list_iterator;
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
        const_vertex_list_iterator myVertex;

    public:
        vertex_iterator() :
            myVertex(NULL)
        {}

        vertex_iterator(const_vertex_list_iterator v) :
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
     friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor i, vertex_descriptor j, Graph& g) {
        edge_descriptor resultEdgeDescriptor = std::make_pair(i , j);
        for (adjacency_iterator a = g.myVertexList[i].begin(); a != g.myVertexList[i].end(); ++a) {
            if (*a == j) {
                return std::make_pair(resultEdgeDescriptor, false);
            }
        }
        g.myVertexList[i].push_back(j);
        g.myEdges.insert(resultEdgeDescriptor);
        assert(g.valid());
        return std::make_pair(resultEdgeDescriptor, true);
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
        assert(g.valid());
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
     friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor v, const Graph& g) {
        adjacency_iterator b = ++(g.myVertexList[v].begin());
        adjacency_iterator e = g.myVertexList[v].end();
        assert(g.valid());
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
     friend std::pair<edge_descriptor, bool> edge (vertex_descriptor s, vertex_descriptor t, const Graph& g) {
        edge_descriptor ed = std::make_pair(s, t);
        edge_iterator ei = g.myEdges.find(ed);
        bool b = ei != g.myEdges.end();
        assert(g.valid());
        return std::make_pair(ed, b);
    }

    // -----
    // edges
    // -----

    /**
     * Returns an iterator-range providing access to the edge set of graph g.
     */
     friend std::pair<edge_iterator, edge_iterator> edges (const Graph& g) {
        edge_iterator b = g.myEdges.begin();
        edge_iterator e = g.myEdges.end();
        assert(g.valid());
        return std::make_pair(b, e);
    }

    // ---------
    // num_edges
    // ---------

    /**
     * Returns the number of edges in the graph g.
     */
     friend edges_size_type num_edges (const Graph& g) {
        assert(g.valid());
        return g.myEdges.size();
    }

    // ------------
    // num_vertices
    // ------------

    /**
     * Returns the number of vertices in the graph g.
     */
     friend vertices_size_type num_vertices (const Graph& g) {
        assert(g.valid());
        return g.myVertexList.end() - g.myVertexList.begin();
    }

    // ------
    // source
    // ------

    /**
     * Returns the source vertex of edge e.
     */
     friend vertex_descriptor source (edge_descriptor ed, const Graph& g) {
        assert(g.valid());
        return ed.first;
    }

    // ------
    // target
    // ------

    /**
     * Returns the target vertex of edge e.
     */
     friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {
        assert(g.valid());
        return ed.second;
    }

    // ------
    // vertex
    // ------

    /**
     * Returns the nth vertex in the graph's vertex list.
     */
     friend vertex_descriptor vertex (vertices_size_type n, const Graph& g) {
        assert(g.valid());
        return g.myVertexList[n].front();
    }

    // --------
    // vertices
    // --------

    /**
     * Returns an iterator-range providing access to the vertex set of
     * graph g.
     */
     friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& g) {
        vertex_iterator b = vertex_iterator(g.myVertexList.begin());
        vertex_iterator e = vertex_iterator(g.myVertexList.end());
        assert(g.valid());
        return std::make_pair(b, e);
    }

private:
    // ----
    // data
    // ----

    vertex_list myVertexList;

    // Turns out, boost just keeps a set of all their edges
    edge_list  myEdges;

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
            result =(std::distance(i.begin(), i.end()) > 0) &&
                    (*(i.begin()) == i - myVertexList.begin());

            // Assert there are no parallel paths
            for (adjacency_iterator j = ++i.begin(); j != i.end() && result; ++j) {
                adjacency_list::difference_type count = std::count(i.begin(), i.end(), *j);
                result = result && (count < 2);
                ++edgesCounter;
            }
        }

        result = result && (edgesCounter == myEdges.size());
        return result;
    }

public:
    // ------------
    // constructors
    // ------------

    /**
     * Construct a new Graph
     */
     Graph () {
        // Nothing to be done but assert preconditions
        assert(valid());
    }
};

// ---------
// has_cycle
// ---------

/**
 * Recurse through the graph, checking every path to see if we
 * can hit the same vertex twice
 *
 * @return true if there is a cycle from v onward
 *         false otherwise
 */
template <typename G>
bool has_cycle_helper (const G& g, std::set<typename G::vertex_descriptor>& m, typename G::vertex_descriptor v) {
    typedef typename G::vertex_descriptor vertex_descriptor;
    typedef typename G::vertex_iterator vertex_iterator;
    typedef typename G::edge_iterator edge_iterator;
    typedef typename G::adjacency_iterator adjacency_iterator;

    if (m.find(v) != m.end())
        return true;

    m.insert(v);
    std::pair<adjacency_iterator, adjacency_iterator> adjs = adjacent_vertices(v, g);
    while (adjs.first != adjs.second) {
        if (has_cycle_helper(g, m, *(adjs.first)))
            return true;
        ++adjs.first;
    }
    m.erase(v);
    return false;
}

/**
 * depth-first traversal
 * three colors
 *
 * @return true if g has a cycle
 *         false otherwise
 */
template <typename G>
bool has_cycle (const G& g) {
    typedef typename G::vertex_descriptor vertex_descriptor;
    typedef typename G::vertex_iterator vertex_iterator;
    std::set<vertex_descriptor> m;
    std::pair<vertex_iterator, vertex_iterator> bounds = vertices(g);

    // Empty graphs aren't cyclical
    if (bounds.first == bounds.second)
        return false;

    vertex_descriptor start = *(bounds.first);

    return has_cycle_helper(g, m, start);
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
    // --- typedefs ---
    typedef typename G::vertex_descriptor vertex_descriptor;
    typedef typename G::vertices_size_type vertices_size_type;
    typedef typename G::vertex_list vertex_list;
    typedef typename G::vertex_iterator vertex_iterator;
    typedef typename G::edge_list edge_list;
    typedef typename G::edge_iterator edge_iterator;
    typedef typename G::adjacency_list adjacency_list;
    typedef typename G::adjacency_iterator adjacency_iterator;

    typedef std::list<vertex_descriptor> linked_list;
    typedef typename linked_list::iterator linked_list_iterator;
    typedef typename std::pair< vertex_descriptor, linked_list > vertex_pair;
    typedef typename std::vector< vertex_pair > pair_vector;
    typedef typename pair_vector::iterator vector_iterator;

    typedef std::priority_queue<vertex_descriptor,
                                std::vector<vertex_descriptor>,
                                std::greater<vertex_descriptor> >
                                min_priority_queue;

    pair_vector v;

    std::pair<vertex_iterator, vertex_iterator> vertexBounds = vertices(g);
    while (vertexBounds.first != vertexBounds.second) {
        const vertex_descriptor& vd = *(vertexBounds.first);
        std::pair<adjacency_iterator, adjacency_iterator> ad = adjacent_vertices(vd, g);
        v.push_back(std::make_pair(vd, linked_list(ad.first, ad.second)));
        ++vertexBounds.first;
    }

    min_priority_queue q;

    while(!v.empty() || !q.empty()) {
        for(vector_iterator i = v.begin(); i != v.end();) {
            if(i->second.size() == 0) {
                q.push(i->first);
                i = v.erase(i);
            }
            else
                ++i;
        }

        assert(!q.empty());

        vertex_descriptor nextVertex = q.top();
        *x++ = nextVertex;
        q.pop();
        for(vector_iterator i = v.begin(); i != v.end(); ++i) {
            i->second.remove(nextVertex);
        }
    }
}

#endif // Graph_h
