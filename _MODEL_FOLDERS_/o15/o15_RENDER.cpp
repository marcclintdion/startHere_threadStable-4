    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o15_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o15_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o15_FilePath = "_MODEL_FOLDERS_/o15/o15.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o15_FromHDtoSystemRAM, 0, NULL);                               
            o15_isLoaded = true;                                                             
        }                                                                                   
        if(o15_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o15, o15_COLORMAP, FreeImage_GetWidth(dib_o15),  FreeImage_GetHeight(dib_o15) );     
            delete_o15_FromSystemRAM();                                                      
            o15_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o15_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o15_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o15_POSITION[0] + moveSet[0], 
                                                o15_POSITION[1] + moveSet[1], 
                                                o15_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o15_ROTATION[0], 
                                                o15_ROTATION[1], 
                                                o15_ROTATION[2],  
                                                o15_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o15_ROTATION[0], 
                                                o15_ROTATION[1], 
                                                o15_ROTATION[2], 
                                                o15_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o15_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 33873, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o15_isActive == false && o15_isLoaded == true)                                         
    {                                                                                       
        if(o15_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o15_COLORMAP);                                              
            o15_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o15_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
