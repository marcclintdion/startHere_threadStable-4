setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o7_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o7_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o7_POSITION[0] + moveSet[0],
                                o7_POSITION[1] + moveSet[1], 
                                o7_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o7_ROTATION[0],
                                o7_ROTATION[1], 
                                o7_ROTATION[2], 
                                o7_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 38469, GL_UNSIGNED_INT, 0); 
