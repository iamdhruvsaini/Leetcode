/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    //peak index in mountain array
    int peak( MountainArray &mountainArr){
        int s=0;
        int e=mountainArr.length()-1;
        // cout<<2;
        while(s<e){
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;

    }
    int binarySearch1(MountainArray &mountainArr,int s,int e,int t){

        while(s<=e){
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid)==t)return mid;
            
            if(mountainArr.get(mid)>t){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;

    }

     int binarySearch2(MountainArray &mountainArr,int s,int e,int t){

        while(s<=e){
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid)==t)return mid;
            
            if(mountainArr.get(mid)<t){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;

    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        if(mountainArr.length()<3)return -1;
        int peakIndex=peak(mountainArr);
        int temp=binarySearch1(mountainArr,0,peakIndex-1,target);
        if(temp!=-1){
            return temp;
        }
        else{
            return binarySearch2(mountainArr,peakIndex,mountainArr.length()-1,target);
        }
        
    }
};