#include "font.h"

//Constructor
FontLib::FontLib()
{
	if(!base)
	{
		std::cout<<"[Starting Font Engine]"<<std::endl;
		
		//build the font
		buildFont();
	}
}

//Destructor
FontLib::~FontLib()
{
	std::cout <<"[Ending Font Engine]"<<std::endl;
	//clean up
	killFont();
}

//Deallocate the font
void FontLib::killFont()
{
	//Delete the display list
    glDeleteLists( base, 96 );
}

#ifdef __linux__
//Build the font
void FontLib::buildFont(void )
{
	//X.org data
    Display *dpy;          
    XFontStruct *fontInfo;

   	//Create a display list
    base = glGenLists( 96 );

	//Get the current X display
    dpy=glXGetCurrentDisplay();
    
   	//Load a reasonably prevalent font type
    fontInfo = XLoadQueryFont( dpy, "-adobe-helvetica-medium-r-normal--12-*-*-*-p-*-iso8859-1" );

   	//Bail out if font is unavailable
    if ( fontInfo == NULL )
	{
	    fontInfo = XLoadQueryFont( dpy, "fixed" );
	    
	    if ( fontInfo == NULL )
		{
		    fprintf( stderr, "no X font available?\n" );
		    return;
		}
	}

    //Set GLX to use said font
    glXUseXFont( fontInfo->fid, 32, 96, base );

  	//Free the X.org font
    XFreeFont( dpy, fontInfo );


    return;
}
#else


//Build the font (add windows/OSX/etc version here) 
void FontLib::buildFont(void )
{
	

    return;
}
#endif

//Text output (akin to printf)
void FontLib::glPrint( const char *fmt, ... )
{
	//temporary text storage variable
    char text[256]; 
    va_list ap;     

  	
    if ( fmt == NULL )
	return;

  	//step through unknown arguments (aka the ... after the inital const char*)
    va_start( ap, fmt );
    
    //Add them into the temporary text variable 
    vsprintf( text, fmt, ap );
    
    va_end( ap );

	//Get ready to work with the display list
    glPushAttrib( GL_LIST_BIT );

 	//Set up display list to work with text
    glListBase( base - 32 );

   	//Disable texturing on the text
    glDisable(GL_TEXTURE_2D);
    
    //Call the list (using the text as an index to the list)
    glCallLists( strlen( text ), GL_UNSIGNED_BYTE, text );
    
    glEnable(GL_TEXTURE_2D);

	
    glPopAttrib( );
}

