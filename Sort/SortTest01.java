package com.zhuguozhu.p1;

/**
 * ≈≈–Ú∏¥œ∞
 * @author Guozhu Zhu
 * @date 2018/3/17
 * @version 1.0
 *
 */
public class SortTest01 {
	
	public static void main(String[] args) {
		int[] arr = {1, 7, 9, 8, 4};
		//sort1(arr);
		//sort2(arr);
	    //sort3(arr);
		sort4(arr, 0, arr.length-1);
		for (int i : arr) {
			System.out.println(i);
		}
	}
	
	/**
	 * √∞≈›≈≈–Ú
	 */
	public static void sort1(int[] arr) {
		for (int i = 0; i < arr.length-1; i++) {
			for (int j = 0; j < arr.length-1-i; j++) {
				if (arr[j] > arr[j+1]) {
					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	
	/**
	 * —°‘Ò≈≈–Ú
	 */
	public static void sort2(int[] arr) {
	    for (int i = 0; i < arr.length; i++) {
	    	for (int j = i+1; j < arr.length; j++) {
	    		if(arr[i] > arr[j]) {
	    			int temp = arr[i];
	    			arr[i] = arr[j];
	    			arr[j] = temp;
	    		}
	    	}
	    }
	}
	
	/**
	 * ≤Â»Î≈≈–Ú
	 * @param arr
	 */
	public static void sort3(int[] arr) {
		int j = 0;
		for (int i = 1; i < arr.length; i++) {
			int temp = arr[i];
			j = i-1;
			while (j >= 0 && temp < arr[j]) {
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = temp;
		}
	}
	
	/**
	 * øÏÀŸ≈≈–Ú
	 */
	public static void sort4(int[] arr, int left, int right) {
		if (left > right) {
			return ;
		}
		int i = left;
		int j = right;
		int key = arr[left];
		while (i < j) {
			while (i < j && key <= arr[j]) {
				j--;
			}
			arr[i] = arr[j];
			while (i < j && key >= arr[i]) {
				i++;
			}
			arr[j] = arr[i];
		}
		arr[i] = key;
		sort4(arr, left, i-1);
		sort4(arr, i+1, right);
	}

}
