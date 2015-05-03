    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(rocks_o15_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(rocks_o15_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            rocks_o15_FilePath = "_MODEL_FOLDERS_/rocks_o15/o15_rocks.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_rocks_o15_FromHDtoSystemRAM, 0, NULL);                               
            rocks_o15_isLoaded = true;                                                             
        }                                                                                   
        if(rocks_o15_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_rocks_o15, rocks_o15_COLORMAP, FreeImage_GetWidth(dib_rocks_o15),  FreeImage_GetHeight(dib_rocks_o15) );     
            delete_rocks_o15_FromSystemRAM();                                                      
            rocks_o15_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, rocks_o15_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o15_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, rocks_o15_POSITION[0] + moveSet[0], 
                                                rocks_o15_POSITION[1] + moveSet[1], 
                                                rocks_o15_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    rocks_o15_ROTATION[0], 
                                                rocks_o15_ROTATION[1], 
                                                rocks_o15_ROTATION[2],  
                                                rocks_o15_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, rocks_o15_ROTATION[0], 
                                                rocks_o15_ROTATION[1], 
                                                rocks_o15_ROTATION[2], 
                                                rocks_o15_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, rocks_o15_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 2490, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(rocks_o15_isActive == false && rocks_o15_isLoaded == true)                                         
    {                                                                                       
        if(rocks_o15_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &rocks_o15_COLORMAP);                                              
            rocks_o15_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        rocks_o15_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  
