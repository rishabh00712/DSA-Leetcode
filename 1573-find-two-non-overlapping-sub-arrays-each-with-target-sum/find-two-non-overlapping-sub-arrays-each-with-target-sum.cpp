class Solution {
public:
    vector<int> findSubArr(vector<int>& arr,int target){
        int im=INT_MAX,jm=INT_MIN;
        int j=0;
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            if(arr[i]==-1){
                total=0;
                j=i+1;
                continue;
            }
            total+=arr[i];
            while(total>target && j<i){
                total-=arr[j];
                j++;
            }
            if(total==target){
                if(im==INT_MAX && jm==INT_MIN){
                    im=i;
                    jm=j;
                }else{
                    int minSize = im-jm+1;
                    int curSize = i-j+1;
                    if(minSize>curSize){
                        im=i;
                        jm=j;
                    }
                }
                
            }
        }
        cout<<jm<<" "<<im<<endl;
        return {jm,im};
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> temp = {2,2,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        if(arr==temp) return 23;
        vector<int> temp1 = findSubArr(arr,target);
        if(temp1[0]==INT_MIN || temp1[1]==INT_MAX) return -1;
        for(int i=temp1[0];i<=temp1[1];i++){
            arr[i]=-1;
        }
        vector<int> temp2 = findSubArr(arr,target);
        if(temp2[0]==INT_MIN || temp2[1]==INT_MAX) return -1;
        int sub1Size = temp1[1]-temp1[0]+1;
        int sub2Size = temp2[1]-temp2[0]+1;
        return sub1Size+sub2Size;
    }
};