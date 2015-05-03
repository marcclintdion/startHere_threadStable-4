//===============================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------
//===============================================================================================================================
void ConfigureAndLoadTexture(GLubyte *textureData, GLuint &currentTextureHandle, GLint texWidth, GLint texHeight )
{

             glGenTextures( 1, &currentTextureHandle );
		     glBindTexture( GL_TEXTURE_2D, currentTextureHandle );


        //============================================
        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        //---------------
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        ////glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
        //---------------
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth,  texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        #endif
        //-------------------------------------------------------------------------------------------------------
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        //----------------
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	  
        //----------------        
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
        //----------------
        glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif

}
//===============================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------
//===============================================================================================================================


    //==================================================================
    #include "_MODEL_FOLDERS_/o11/o11_ASSET_STREAM.cpp"
    //==================================================================
    #include "_MODEL_FOLDERS_/o18/o18_ASSET_STREAM.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o17\o17_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o19\o19_ASSET_STREAM.cpp"     


    //========================================================================= 
    #include "_MODEL_FOLDERS_\o12\o12_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o10\o10_ASSET_STREAM.cpp"     




    //========================================================================= 
    #include "_MODEL_FOLDERS_\o1\o1_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o21\o21_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_B\o8_B_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_A\o8_A_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o5\o5_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o15\o15_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o16\o16_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o6\o6_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o14\o14_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o13\o13_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o7\o7_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o20\o20_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o9\o9_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o2\o2_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o4\o4_ASSET_STREAM.cpp"     
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o3\o3_ASSET_STREAM.cpp"     
    //=========================================================================
    #include "_MODEL_FOLDERS_\Cube\Cube_ASSET_STREAM.cpp"     
    //=========================================================================
    #include "_MODEL_FOLDERS_\domeTree_x4\domeTree_x4_ASSET_STREAM.cpp"     
    //=========================================================================
    #include "_MODEL_FOLDERS_\rocks_o15\rocks_o15_ASSET_STREAM.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o17\rocks_o17_ASSET_STREAM.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o18\rocks_o18_ASSET_STREAM.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o19\rocks_o19_ASSET_STREAM.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o20\rocks_o20_ASSET_STREAM.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o21\rocks_o21_ASSET_STREAM.cpp"





