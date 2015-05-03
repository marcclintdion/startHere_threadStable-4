    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o20_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o20_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o20_FilePath = "_MODEL_FOLDERS_/o20/o20.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o20_FromHDtoSystemRAM, 0, NULL);                               
            o20_isLoaded = true;                                                             
        }                                                                                   
        if(o20_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o20, o20_COLORMAP, FreeImage_GetWidth(dib_o20),  FreeImage_GetHeight(dib_o20) );     
            delete_o20_FromSystemRAM();                                                      
            o20_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o20_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o20_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o20_POSITION[0] + moveSet[0], 
                                                o20_POSITION[1] + moveSet[1], 
                                                o20_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o20_ROTATION[0], 
                                                o20_ROTATION[1], 
                                                o20_ROTATION[2],  
                                                o20_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o20_ROTATION[0], 
                                                o20_ROTATION[1], 
                                                o20_ROTATION[2], 
                                                o20_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o20_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 28899, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o20_isActive == false && o20_isLoaded == true)                                         
    {                                                                                       
        if(o20_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o20_COLORMAP);                                              
            o20_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o20_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
