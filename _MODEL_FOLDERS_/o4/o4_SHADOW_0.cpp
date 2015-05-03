setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o4_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o4_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o4_POSITION[0] + moveSet[0],
                                o4_POSITION[1] + moveSet[1], 
                                o4_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o4_ROTATION[0],
                                o4_ROTATION[1], 
                                o4_ROTATION[2], 
                                o4_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 35673, GL_UNSIGNED_INT, 0); 
