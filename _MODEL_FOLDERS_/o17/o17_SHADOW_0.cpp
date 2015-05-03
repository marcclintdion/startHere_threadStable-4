setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o17_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o17_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, o17_POSITION[0] + moveSet[0],
                                o17_POSITION[1] + moveSet[1], 
                                o17_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    o17_ROTATION[0],
                                o17_ROTATION[1], 
                                o17_ROTATION[2], 
                                o17_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    glDrawElements(GL_TRIANGLES, 34665, GL_UNSIGNED_INT, 0); 
