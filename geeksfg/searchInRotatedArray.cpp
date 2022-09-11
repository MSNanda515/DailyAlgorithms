class Solution{
    int findRotIndex(int A[], int l, int h) {
        int beg = l, end = h;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (mid > beg && A[mid] < A[mid-1]) {
                return mid;
            } else if (mid < end && A[mid] > A[mid+1]) {
                return mid+1;
            } else if (A[mid] > A[h]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return 0;
    }
    
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int piv = findRotIndex(A, 0, h);
        int beg, end;
        if (key <= A[h]) {
            beg = piv;
            end = h;
        } else {
            beg = l;
            end = piv-1;
        }
        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (A[mid] == key) {
                return mid;
            } else if (A[mid] > key) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
            
        }
        return -1;
    }
};