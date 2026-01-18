/* SPDX-License-Identifier: MIT */
/* Copyright (c) Kirikiri SDL2 Developers */

#ifndef OpenGLScreenH
#define OpenGLScreenH

#include <SDL3/SDL.h>

#include "OpenGLHeader.h"
#include "ComplexRect.h"
#include "WindowImpl.h"

class tTVPOpenGLScreen
{
	TTVPWindowForm* Form;

	GLint mDefaultFrameBufferId;
public:
	tTVPOpenGLScreen( TTVPWindowForm* form );

	bool Initialize();
	void Destroy();
	bool IsInitialized() const;

	void Swap();

	GLint GetSurfaceWidth() const;
	GLint GetSurfaceHeight() const;
	void GetDrawableSize(GLint &w, GLint &h) const;

	static bool CheckGLErrorAndLog(const tjs_char* funcname=nullptr);

	void SetScissorRect( const tTVPRect& rect );
	void DisableScissorRect();

	GLint GetDefaultFrameBufferId() const { return mDefaultFrameBufferId; }

	void SetWaitVSync( bool b );
};
#endif
