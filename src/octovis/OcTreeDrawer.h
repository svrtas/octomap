// $Id$

/**
 * Octomap:
 * A  probabilistic, flexible, and compact 3D mapping library for robotic systems.
 * @author K. M. Wurm, A. Hornung, University of Freiburg, Copyright (C) 2009.
 * @see http://octomap.sourceforge.net/
 * License: GNU GPL v2, http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef OCTREEDRAWER_H_
#define OCTREEDRAWER_H_

#include "SceneObject.h"

namespace octomap {

  class OcTreeDrawer: public octomap::SceneObject {
  public:
    OcTreeDrawer();
    virtual ~OcTreeDrawer();
    void clear();
    void draw() const;
    void setOcTree(const octomap::OcTree &octree);

    /// sets alpha level for occupied cells
    void setAlphaOccupied(double alpha);

    void enableOcTree(bool enabled = true);
    void enableOcTreeCells(bool enabled = true) {m_drawOccupied = enabled; };
    void enableFreespace(bool enabled = true) {m_drawFree = enabled; };
    void setMax_tree_depth(unsigned int max_tree_depth) {m_max_tree_depth = max_tree_depth;};

  protected:
    //void clearOcTree();
    void clearOcTreeStructure();

    void drawOctreeGrid() const;
    void drawOccupiedVoxels() const;
    void drawFreeVoxels() const;
    void drawCubes(GLfloat** cubeArray, unsigned int cubeArraySize,
        GLfloat* cubeColorArray = NULL) const;

    //! Initializes the OpenGL visualization for a list of OcTreeVolumes
    //! The array is cleared first, if needed
    void generateCubes(const std::list<octomap::OcTreeVolume>& points,
        GLfloat*** glArray, unsigned int& glArraySize, GLfloat** glColorArray = NULL);

    //! clear OpenGL visualization
    void clearCubes(GLfloat*** glArray, unsigned int& glArraySize, GLfloat** glColorArray = NULL);

    void initOctreeGridVis();


    //! OpenGL representation of Octree cells (cubes)

    GLfloat** m_occupiedThresArray;
    unsigned int m_occupiedThresSize;
    GLfloat** m_freeThresArray;
    unsigned int m_freeThresSize;
    GLfloat** m_occupiedArray;
    unsigned int m_occupiedSize;
    GLfloat** m_freeArray;
    unsigned int m_freeSize;

    //! Color array for occupied cells (height)
    GLfloat* m_occupiedThresColorArray;
    GLfloat* m_occupiedColorArray;

    //! OpenGL representation of Octree (grid structure)
    // TODO: put in its own drawer object!
    GLfloat* octree_grid_vertex_array;
    unsigned int octree_grid_vertex_size;

    std::list<octomap::OcTreeVolume> m_grid_voxels;

    bool m_drawOccupied;
    bool m_drawOcTreeGrid;
    bool m_drawFree;
    bool m_octree_grid_vis_initialized;

    unsigned int m_max_tree_depth;
    double m_alphaOccupied;

  };
}

#endif /* OCTREEDRAWER_H_ */
