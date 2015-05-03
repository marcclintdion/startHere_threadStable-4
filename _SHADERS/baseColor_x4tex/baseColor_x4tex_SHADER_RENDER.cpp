ColorRenderMatrixFunctions();

 
 glUseProgram(baseColor_x4tex_SHADER);
          //------------------------------------------------------------------------------
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
          glEnableVertexAttribArray(0);
          glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
          glEnableVertexAttribArray(1);
          glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
          glEnableVertexAttribArray(2);
          //------------------------------------------------------------------------------------------------

          glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_baseColor_x4tex,                1, 0,    tempMatrix_D);
          glUniformMatrix4fv(UNIFORM_MODELVIEW_MATRIX_baseColor_x4tex,                 1, 0,    modelViewMatrix);

          //---------------------------------------
          glUniform2f(UNIFORM_UV_ADJUST_baseColor_x4tex,         adjust_UVs[0], adjust_UVs[1]);          
          
          glUniform1i(UNIFORM_TEX_COLOR_baseColor_x4tex,                  0);

    //==========================================================================
