    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o4_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o4_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o4_FilePath = "_MODEL_FOLDERS_/o4/o4.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o4_FromHDtoSystemRAM, 0, NULL);                               
            o4_isLoaded = true;                                                             
        }                                                                                   
        if(o4_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o4, o4_COLORMAP, FreeImage_GetWidth(dib_o4),  FreeImage_GetHeight(dib_o4) );     
            delete_o4_FromSystemRAM();                                                      
            o4_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
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
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o4_ROTATION[0], 
                                                o4_ROTATION[1], 
                                                o4_ROTATION[2], 
                                                o4_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o4_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 35673, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o4_isActive == false && o4_isLoaded == true)                                         
    {                                                                                       
        if(o4_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o4_COLORMAP);                                              
            o4_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o4_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
