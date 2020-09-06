class Solution:
    def detectCycle(self, head):
        runner = walker = head

        while runner and runner.next:
            runner = runner.next.next
            walker = walker.next
            if runner == walker:
                seeker = head
                while seeker != walker:
                    walker = walker.next
                    seeker = seeker.next
                return walker
