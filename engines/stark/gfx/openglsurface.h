/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef STARK_GFX_OPENGL_SURFACE_H
#define STARK_GFX_OPENGL_SURFACE_H

#include "engines/stark/gfx/surfacerenderer.h"
#include "engines/stark/gfx/opengl.h"

#include "math/vector2d.h"

#if defined(USE_OPENGL_GAME)

namespace Stark {
namespace Gfx {

class OpenGLDriver;
class Bitmap;

/**
 * An programmable pipeline OpenGL surface renderer
 */
class OpenGLSurfaceRenderer : public SurfaceRenderer {
public:
	OpenGLSurfaceRenderer(OpenGLDriver *gfx);
	virtual ~OpenGLSurfaceRenderer();

	// SurfaceRenderer API
	void render(const Bitmap *bitmap, const Common::Point &dest) override;
	void render(const Bitmap *bitmap, const Common::Point &dest, uint width, uint height) override;
	void fill(const Color &color, const Common::Point &dest, uint width, uint height) override;

private:
	struct SurfaceVertex {
		float x;
		float y;
	};

	Math::Vector2d normalizeOriginalCoordinates(int x, int y) const;
	Math::Vector2d normalizeCurrentCoordinates(int x, int y) const;
	void convertToVertices(SurfaceVertex *vertices, const Common::Point &dest, uint width, uint height) const;

	OpenGLDriver *_gfx;
};

} // End of namespace Gfx
} // End of namespace Stark

#endif // defined(USE_OPENGL_GAME)

#endif // STARK_GFX_OPENGL_SURFACE_H
