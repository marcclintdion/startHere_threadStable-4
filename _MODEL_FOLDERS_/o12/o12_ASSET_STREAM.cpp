#ifdef WIN32 
void load_o12_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o12 = FreeImage_GetFileType(o12_FilePath, 0);                       
    dib_o12   = FreeImage_Load(fifmt_o12, o12_FilePath, 0);                    
    temp_o12  = dib_o12;                                                      
    dib_o12   = FreeImage_ConvertTo32Bits(temp_o12);                          
    FreeImage_Unload(temp_o12);                                            

    if( dib_o12 != NULL )                                                    
    {                                                                       
        pixels_o12 = (BYTE*)FreeImage_GetBits(dib_o12);                       
    }                                                                     

    o12_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o12_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o12 != NULL )                                                    
    {                                                                       
        free(pixels_o12);                                                    
        FreeImage_Unload(dib_o12);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
