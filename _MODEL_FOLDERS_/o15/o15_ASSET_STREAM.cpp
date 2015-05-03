#ifdef WIN32 
void load_o15_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o15 = FreeImage_GetFileType(o15_FilePath, 0);                       
    dib_o15   = FreeImage_Load(fifmt_o15, o15_FilePath, 0);                    
    temp_o15  = dib_o15;                                                      
    dib_o15   = FreeImage_ConvertTo32Bits(temp_o15);                          
    FreeImage_Unload(temp_o15);                                            

    if( dib_o15 != NULL )                                                    
    {                                                                       
        pixels_o15 = (BYTE*)FreeImage_GetBits(dib_o15);                       
    }                                                                     

    o15_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o15_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o15 != NULL )                                                    
    {                                                                       
        free(pixels_o15);                                                    
        FreeImage_Unload(dib_o15);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
