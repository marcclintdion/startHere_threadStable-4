setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, gemini_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gemini_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, gemini_POSITION[0] + moveSet[0],
                                gemini_POSITION[1] + moveSet[1], 
                                gemini_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    gemini_ROTATION[0],
                                gemini_ROTATION[1], 
                                gemini_ROTATION[2], 
                                gemini_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 804, GL_UNSIGNED_INT, 0); 
