setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o18_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o18_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o18_POSITION[0] + moveSet[0],
                                o18_POSITION[1] + moveSet[1], 
                                o18_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o18_ROTATION[0],
                                o18_ROTATION[1], 
                                o18_ROTATION[2], 
                                o18_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 34023, GL_UNSIGNED_INT, 0); 
