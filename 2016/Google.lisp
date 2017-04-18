(defun bleatrix (n)
  ;; Function
  ;; ========
  ;;
  ;; Description:
  ;; ===========
  ;;  Bleatrix Trotter the sheep has devised a strategy that helps her fall asleep faster. First, she picks a number N. Then she starts naming N, 2 × N, 3 × N, and so
  ;; on. Whenever she names a number, she thinks about all of the digits in that number. She keeps track of which digits (0, 1, 2, 3, 4, 5, 6, 7, 8, and 9) she has see
  ;; at least once so far as part of any number she has named. Once she has seen each of the ten digits at least once, she will fall asleep.
  ;;
  ;; Input:
  ;; =====
  ;;  [1] - n: a integer chosen by Bleatrix Trotter
  ;;
  ;; Output:
  ;; ======
  ;;  Last number that Bleatrix will name before falling asleep.
  ;; In case n is 0 Bleatrix will never sleep, output INSONIA.
  (let ((all-numbers '(0 1 2 3 4 5 6 7 8 9))))
  (labels ((separete-n (sn d)
		       ;; Local-Function
		       ;; ==============
		       ;;
		       ;; Input:
		       ;; =====
		       ;;  [1] - sn: a simple integer
		       ;;  [2] - d: divided, init as 10
		       ;;
		       ;; Output:
		       ;; ======
		       ;;  Separate sn to each integer and put on a list
		       ;;
		       ;; Example:
		       ;; =======
		       ;;  [1]:
		       ;;  > (separete-n 3098)
		       ;;    '(8 9 0 3)
		       ;;  [2]:
		       ;;  > (separete-n 4)
		       ;;    '(4)
		       (if (eq (/ sn d) 0) sn
			 (push (mod sn d)
			       (separete-n (/ sn d)
					   (* 10 d)))))))
  (if (eq n 0) 'INSONIA
    ( 
