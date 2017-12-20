#pragma once
#include <GL\glew.h>
#include "Vertex.h"  
#include <glm/glm.hpp>
#include <vector>
namespace Engine {

	enum class GlyphSortType {
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
	};

	struct Glyph {
		GLuint texture;
		float depth;

		Vertex topLeft;
		Vertex bottomleft;
		Vertex bottomright;
		Vertex topRight;
	};


	class RenderBatch {
	public :
		RenderBatch(GLuint Offset, GLuint NumVertices, GLuint Texture) : offset(Offset),
			numVertices(NumVertices), texture(Texture) {

		}
		GLuint offset;
		GLuint numVertices;
		GLuint texture;

	};
	class SpriteBatch
	{
	public:
		SpriteBatch();
		~SpriteBatch();
		void init();

		void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
		void end();

		void draw(glm::vec4& destinationRectangle, const glm::vec4& uvRect, GLuint texture, float depth,const Color& color);

		void renderBatch();
	private:
		void createRenderBatches();
		void createVertexArray();
		void sortGlyphs();

		static bool compareFrontToBack(Glyph* a, Glyph* b);
		static bool compareBackToFront(Glyph* a, Glyph* b);
		static bool compareTexture(Glyph* a, Glyph* b);
		GlyphSortType _sortType;
		GLuint _vbo;
		GLuint _vao;
		std::vector <Glyph*> _glyphs;
		std::vector <RenderBatch> _renderBatches;
	};
}



